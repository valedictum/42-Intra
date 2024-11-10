from django.urls import path
from . import views

urlpatterns = [
	path('add/<str:username>/', views.add_friend, name='add_friend'),
	path('remove/<str:username>/', views.remove_friend, name='remove_friend'),
	path('friends/', views.get_friends_list, name='get_friends_list'),
	path('block/<str:username>/', views.block_user, name='block_user'),
	path('unblock/<str:username>/', views.unblock_user, name='unblock_user'),
	path('blocks/', views.get_block_list, name='get_block_list'),
    # path('sendFriendRequest/<str:username>/', views.send_friend_request, name='send_friend_request'),
    # path('friendRequests/', views.list_friend_requests, name='return_friend_request'),
    # path('acceptRequest/<str:username>/', views.accept_friend_request, name='accept_request'),
    # path('rejectRequest/<str:username>/', views.reject_friend_request, name='reject_request'),
    # path('friend_profile/<str:username>/', views.get_friend_profile, name='get_friend_profile'),
]
