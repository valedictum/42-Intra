from rest_framework.decorators import api_view
from rest_framework.response import Response
from rest_framework import status
from .models import FriendlyMatch
from .serializers import FriendlyMatchSerializer
from accounts.models import User
from django.utils import timezone

@api_view(['POST'])
def create_friendly_match(request):
    if request.user.is_authenticated:
        friendly_match = FriendlyMatch.objects.create(
            name=request.data['name'],
            player1=User.objects.get(id=request.user.id),
            score1=0,
            player2=None,
            score2=0,
            match_date=timezone.now()
        )
        serializer = FriendlyMatchSerializer(friendly_match)
        return Response(serializer.data, status=status.HTTP_201_CREATED)
    return Response({'Error': 'HTTP_401_UNAUTHORIZED'}, status=status.HTTP_401_UNAUTHORIZED)

@api_view(['GET'])
def list_friendly_matches(request):
    if request.user.is_authenticated:
        matches = FriendlyMatch.objects.all()
        serializer = FriendlyMatchSerializer(matches, many=True)
        return Response(serializer.data, status=status.HTTP_200_OK)
    return Response({'Error': 'HTTP_401_UNAUTHORIZED'}, status=status.HTTP_401_UNAUTHORIZED)

@api_view(['GET'])
def get_friendly_match(request, match_id):
    if request.user.is_authenticated:
        try:
            match = FriendlyMatch.objects.get(id=match_id)
            serializer = FriendlyMatchSerializer(match)
            return Response(serializer.data, status=status.HTTP_200_OK)
        except FriendlyMatch.DoesNotExist:
            return Response({'Error': 'Match not found'}, status=status.HTTP_404_NOT_FOUND)
    return Response({'Error': 'HTTP_401_UNAUTHORIZED'}, status=status.HTTP_401_UNAUTHORIZED)

@api_view(['POST'])
def submit_match_result(request, match_id):
    if request.user.is_authenticated:
        try:
            match = FriendlyMatch.objects.get(id=match_id)
            data = request.data.copy()

            # Update player scores
            match.score1 = data.get('score1', match.score1)
            match.score2 = data.get('score2', match.score2)

            # Determine and set the winner based on the score
            if match.score1 > match.score2:
                match.winner = match.player1
            elif match.score2 > match.score1:
                match.winner = match.player2
            else:
                match.winner = None  # No winner if it's a draw

            match.save()

            return Response(FriendlyMatchSerializer(match).data, status=status.HTTP_200_OK)
        except FriendlyMatch.DoesNotExist:
            return Response({'Error': 'Match not found'}, status=status.HTTP_404_NOT_FOUND)
    return Response({'Error': 'HTTP_401_UNAUTHORIZED'}, status=status.HTTP_401_UNAUTHORIZED)

# @api_view(['DELETE'])
# def delete_friendly_match(request, match_id):
#     if request.user.is_authenticated:
#         try:
#             match = FriendlyMatch.objects.get(id=match_id)
#             match.delete()
#             return Response({'message': 'Match deleted successfully'}, status=status.HTTP_204_NO_CONTENT)
#         except FriendlyMatch.DoesNotExist:
#             return Response({'Error': 'Match not found'}, status=status.HTTP_404_NOT_FOUND)
#     return Response({'Error': 'HTTP_401_UNAUTHORIZED'}, status=status.HTTP_401_UNAUTHORIZED)


@api_view(['POST'])
def delete_friendly_match(request):
    if request.user.is_authenticated:
        try:
            match_name = request.data['name']
            match = FriendlyMatch.objects.get(name=match_name)
            match.delete()
            return Response({'message': 'Match deleted successfully'}, status=status.HTTP_204_NO_CONTENT)
        except FriendlyMatch.DoesNotExist:
            return Response({'Error': 'Match not found'}, status=status.HTTP_404_NOT_FOUND)
    return Response({'Error': 'HTTP_401_UNAUTHORIZED'}, status=status.HTTP_401_UNAUTHORIZED)
