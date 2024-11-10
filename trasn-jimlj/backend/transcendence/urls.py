"""
URL configuration for transcendence project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/5.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path, include
from .router import router
from django.conf import settings

urlpatterns = [
    path('api/admin/', admin.site.urls),
	path("api/v1/auth/", include('accounts.urls')),
    path("api/v1/auth/", include('social_accounts.urls')),
    path("api/chat/", include("chat.urls")),
    path("api/dapp/", include('dapp_storage.urls')),
    path("api/friend/", include('friends_api.urls')),
    path("api/friendship/", include('friendship.urls')),
    path("api/tournament/", include('tournament.urls')),
    path("api/friendly/", include('friendly_match.urls')),
]
# + static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
# Only add this when we are in debug mode.
# if settings.DEBUG:
#     urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
