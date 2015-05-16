#!/bin/bash

PROGDIR="/usr/www/cgi-bin/apps/"
PROGURL="https://github.com/momolemo/karotz-app-TV/blob/master/cgi-bin/apps/progtv"

wget -q -P ${PROGDIR} ${PROGURL} >>/dev/null 2>>/dev/null
