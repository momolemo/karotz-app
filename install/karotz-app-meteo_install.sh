#!/bin/bash

PROGDIR="/usr/www/cgi-bin/apps"
PROGNAME="meteo"
PROGURL="https://raw.githubusercontent.com/momolemo/karotz-app/master/cgi-bin/apps"

curl -s -k ${PROGURL}/${PROGNAME} > ${PROGDIR}/${PROGNAME} 2>>/dev/null

chmod 777 ${PROGDIR}/${PROGNAME}
