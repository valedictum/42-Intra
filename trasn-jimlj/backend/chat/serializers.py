from rest_framework import serializers
from .models import Message, Room
from accounts.serializers import UserSerializer
from django.conf import settings

class RoomSerializer(serializers.ModelSerializer):
    users = UserSerializer(many=True, read_only=True)
    image = serializers.SerializerMethodField('get_image_url')

    class Meta:
        model = Room
        fields = ['id', 'isDirect', 'users', 'admin', 'group_name', 'image']
        
    def get_image_url(self, obj):
        # request = self.context.get("request")
        if obj.image == "groupicon.png":
            return f"{settings.CN_URL}/static/groupicon.png"
        return f"{settings.CN_URL}/media/{obj.image}"
# add image later
class MessageSerializer(serializers.ModelSerializer):
    # room = RoomSerializer()
    sender = UserSerializer()

    class Meta:
        model = Message
        fields = ['id', 'sender', 'message', 'timestamp']
