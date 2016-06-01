# simple-MP3-Player-QT
A simple cross platform mp3 player with playlist that has functionalities like Play, Pause, Stop, Next, Preview, Shuffle and mute using C++(QT Framework)

💎 Scope of the project

To create a simple mp3 player with playlist that has functionalities like Play, Pause, Stop, Next, Preview, Shuffle and mute.
Aim and objective of this project

The aim of this assignment is to produce a suitable design for a software application, followed by an implementation in C++ using Qt library and a documentation of such application.

Objective is to design a simple mp3 player with user-friendly GUI and basic and some advance functionalities of mp3 player.

💎 Functionalities

Program functionalities are followed

➡ Open single or multiple songs and play them.

   o This can be done either using the file button in toolbar or just simply pressing Ctrl+o as the shortcut. And the current status initialized in a label under volume bar.

➡ Play or pause the song on user preference

   o Once the playlist loaded the playlist will be play automatically. User can pause it by either clicking the play button on the tool bar or clicking the GUI button placed in bottom of the window or pressing Space button. And the current status initialized in a label under volume bar.

➡ Stop the song playing
    o User can stop it by either clicking the Stop button on the tool bar or clicking the GUI button placed in bottom of the window or pressing esc button. And the current status initialized in a label under volume bar.

➡ Play next song

   o User can do this by either clicking the next button on the tool bar or clicking the GUI button placed in bottom of the window or pressing PgUp button. And the current status initialized in a label under volume bar.

➡ Play previous song

   o User can do this by either clicking the previous button on the tool bar or clicking the GUI button placed in bottom of the window or pressing PgDn button. And the current status initialized in a label under volume bar.

➡ Shuffle the playlist

   o User can pause it by either clicking the shuffle button on the tool bar or clicking the GUI button placed under the playlist of the window or pressing Ctrl+Tab button. And the current status initialized in a label under volume bar.

➡ Mute song

   o User can mute it by either clicking the mute button on the tool bar or clicking the GUI button placed under the playlist of the window or pressing m button.

➡ Change volume

   o Use can change the volume by using the Dial widget placed under playlist and can see the progress and current volume level on progress bar under it.

Known Issues and Bugs and reasons for that

Following issues and bugs are discovered while testing

➡ When loading the songs to playlist it shows the full file path instead of file name

   o This is because I used QStreingList to store the files paths, but to get the file name it can be easily done by using QString and QFileInfo.MetaData(); but it doesn’t support for QStreingList. i have tried many methods to do that but it won’t work. I have commented those methods I tried in on_actionOpen_triggered().

➡ When playing the song I tried to display the Album art of the song in the player if available, or otherwise play an equalizer gif to give more attractiveness to player, for some reason it’s not working and I couldn’t resolve that

➡ When you clicked shuffle icon it shuffle but can’t restore the playlist

   o It’s because of there’s no such method implemented yet in QMediaPlayer.Shuffle().

➡ When playing the song the title of the song must showing in QLable under the equalizer image. But it’s not showing. But if you stop the song while playing and play again it works. There must be some logical error I couldn’t figure out yet.
