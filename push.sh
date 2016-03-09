#!/bin/sh
## push.sh for MY_PROJECT in /home/gascio_m/rendu
##
## Made by Mathieu GASCIOLLI
## Login   <gascio_m@epitech.net>
##
## Started on  Wed Oct 14 15:27:35 2015 Mathieu GASCIOLLI
## Last update Wed Mar  9 02:33:15 2016 Mathieu GASCIOLLI
##

git add --all
git rm --cached push.sh poker
git commit -am "work"
git push origin master
