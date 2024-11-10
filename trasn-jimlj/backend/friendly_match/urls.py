from django.urls import path
from . import views

urlpatterns = [
    path('matches/create/', views.create_friendly_match, name='create_friendly_match'),
    path('matches/', views.list_friendly_matches, name='list_friendly_matches'),
    path('matches/<int:match_id>/', views.get_friendly_match, name='get_friendly_match'),
    path('matches/<int:match_id>/submit/', views.submit_match_result, name='submit_match_result'),
    # path('matches/<int:match_id>/delete/', views.delete_friendly_match, name='delete_friendly_match'),
    path('matches/delete/', views.delete_friendly_match, name='delete_friendly_match'),
]
