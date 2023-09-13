#!/usr/bin/bash
# https://stackoverflow.com/questions/226703/how-do-i-prompt-for-yes-no-cancel-input-in-a-linux-shell-script
read -n3 -p 'do u really want to update Google Chrome?' yn
case $yn in
	[Yy]* )		
# https://www.andreaminini.com/linux/come-installare-il-browser-chrome-su-linux-ubuntu
		package='google-chrome-stable_current_amd64.deb'
		wget https://dl.google.com/linux/direct/$package
		sudo dpkg -i $package
		rm $(locate $package)
		rm $package;;
	[Nn]* ) exit;;
	* ) echo "Please answer yes or no.";;
esac

