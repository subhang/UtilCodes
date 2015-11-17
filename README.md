# PowerMusic
PowerMusic uses a command line interface to download your favourite song along with its lyrics and as well playing it along with sing along lyrics in the terminal itself and it saves the song along with its lyrics in PowerMusic/Songs_Lyrics folder for future purpose!!


To get going open terminal in Linux or Mac OS X and type:
      
      git clone https://github.com/kushal10/PowerMusic.git
      cd PowerMusic
      chmod 755 PowerMusic
      ./PowerMusic

Hurray! You have setup your environment. 

To listen to your favourite songs along with sing along lyrics just type:

    lyrics song play <song-name>
    
Enjoy!!

MUSIC IS LIFE !!

If you face this error:
WARNING: Your copy of avconv is outdated, update avconv to version 10-0 or newer if you encounter any errors.

Do this :
      sudo add-apt-repository ppa:mc3man/trusty-media
      sudo apt-get update
      sudo apt-get dist-upgrade
      sudo apt-get install ffmpeg
