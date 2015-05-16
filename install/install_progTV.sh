#!/bin/bash

PROGDIR="/usr/www/cgi-bin/apps"
PROGFILE="progtv"
PROGURL="https://github.com/momolemo/karotz-app-TV/blob/master/cgi-bin/apps"

wget -q -O ${PROGDIR}/${PROGFILE} ${PROGURL}/PROGFILE >>/dev/null 2>>/dev/null
