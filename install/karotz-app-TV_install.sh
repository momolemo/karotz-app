#!/bin/bash

PROGDIR="/usr/www/cgi-bin/apps"
PROGNAME="progtv"
PROGURL="https://github.com/momolemo/karotz-app-TV/blob/master/cgi-bin/apps"

curl -s -k ${PROGURL}/${PROGNAME} > ${PROGDIR}/${PROGNAME} 2>>/dev/null

chmod 777 ${PROGDIR}/${PROGNAME}
