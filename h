#!bin/bash


# error precaution.
set -e
# default unzip folder.
DIR='app/main'
mkdir -p "$DIR"

_get_ziplink () {
    local regex
    regex='(https?)://github.com/.+/.+'
    if [[ $UPSTREAM_REPO =~ $regex ]]
    then 
        echo "https://github.com/Sanjeev20012000/prgone/archive/refs/heads/old-pyro.zip"
    else
        echo "https://github.com/gautamajay52/TorrentLeech-Gdrive/archive/refs/heads/master.zip"
    fi
}

_startbot () {
    cd $DIR/*
    sleep 3
    bash start.sh
    sleep 5
}


_setup_repo () {
    local zippath
    zippath="app/master.zip"
    wget -q "https://github.com/Rockykingbhai/ZeetDeploy/blob/master/JKbotBySK.zip" -O "$zippath"
    unzip -qq "$zippath" -d "$DIR"
    rm -rf "$zippath"  
    sleep 5
    _startbot
}


_setup_repo
