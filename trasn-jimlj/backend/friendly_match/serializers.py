from rest_framework import serializers
from .models import FriendlyMatch
from accounts.serializers import UserSerializer

class FriendlyMatchSerializer(serializers.ModelSerializer):
    player1 = UserSerializer()
    player2 = UserSerializer()
    winner = UserSerializer()

    class Meta:
        model = FriendlyMatch
        fields = ['id', 'name', 'player1', 'score1', 'player2', 'score2', 'winner', 'match_date']
