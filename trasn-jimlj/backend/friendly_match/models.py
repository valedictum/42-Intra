from django.db import models
from accounts.models import User

class FriendlyMatch(models.Model):
    name = models.CharField(max_length=100)
    player1 = models.ForeignKey(User, related_name='friendly_player1', on_delete=models.CASCADE, null=True)
    score1 = models.IntegerField(default=0)
    player2 = models.ForeignKey(User, related_name='friendly_player2', on_delete=models.CASCADE, null=True)
    score2 = models.IntegerField(default=0)
    winner = models.ForeignKey(User, related_name='friendly_winner', on_delete=models.SET_NULL, null=True)
    match_date = models.DateTimeField()
