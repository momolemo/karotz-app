
UA="Mozilla/5.0 (Macintosh; Intel Mac OS X 10.7; rv:21.0) Gecko/20100101 Firefox/21.0"

function AcapelaTTS {
   TTS=$1
   VOICE=$2
   NOCACHE=$3
   RVOICE=$4
   MUTE=$5

   MD5FILE=""

   CURL_PARAM=$(echo "&voice="$VOICE"&text="$TTS)                       

   RESULT=`eval $(echo "curl -k --header "Keep-Alive:300" --header "Connection:keep-alive" --header "Content-type:application/x-www-form-urlencoded" -s --data '${CURL_PARAM}' https://acapela-box.com/AcaBox/dovaas.php")`
   RESULT=$(echo $RESULT| awk -F "\"snd_url\":\"" '{print $2}' |awk -F "\",\"" '{print $1}')

   if [ "$RESULT" != "" ]; then

      MD5FILE=$(echo "$TTS""$VOICE" | md5sum | cut -d ' ' -f 1)
      echo $( echo \"$TTS\" | UrlDecode)  > $CNF_DATADIR/Tmp/${MD5FILE}.txt         
      echo $( echo $RVOICE | UrlDecode)  > $CNF_DATADIR/Tmp/${MD5FILE}.voice
      eval $(echo "curl -k -L -A '${UA}' -o $CNF_DATADIR/Tmp/${MD5FILE}.mp3 $RESULT" )  >>/dev/null 2>>/dev/null

      if [ "$5" != "1" ]; then
        Log "[TTS]"  "Playing sound ${MD5FILE}.mp3"
        PlaySound $CNF_DATADIR/Tmp/${MD5FILE}.mp3
     fi

     if [ "$NOCACHE" == "1" ]; then
        rm -f $CNF_DATADIR/Tmp/${MD5FILE}.mp3   >>/dev/null 2>>/dev/null
        rm -f $CNF_DATADIR/Tmp/${MD5FILE}.txt   >>/dev/null 2>>/dev/null
     else
        Log "[TTS]"  "Storing sound ${MD5FILE}.mp3 to cache"
     fi
   fi
   echo ${MD5FILE}
}
   
function AcapelaoldTTS {  
   TTS=$1
   VOICE=$2
   NOCACHE=$3
   RVOICE=$4
   MUTE=$5
   
   MD5FILE=""
   
   CURL_PARAM=$(echo "&voice="$RVOICE"&text="$TTS"&legacy=1")                                                          
   
   RESULT=`eval $(echo "curl --header "Keep-Alive:300" --header "Connection:keep-alive" --header "Content-type:application/x-www-form-urlencoded" -s --data '${CURL_PARAM}' http://ws.openkarotz.org/tts.php")`        

   if [ "$RESULT" != "" ]; then

      MD5FILE=$(echo "$TTS$VOICE" | md5sum | cut -d ' ' -f 1)
      echo $( echo \"$TTS\" | UrlDecode)  > $CNF_DATADIR/Tmp/${MD5FILE}.txt                                             
      echo $( echo $RVOICE | UrlDecode)  > $CNF_DATADIR/Tmp/${MD5FILE}.voice
      eval $(echo "curl -L -A '${UA}' -o $CNF_DATADIR/Tmp/${MD5FILE}.mp3 $RESULT" )  >>/dev/null 2>>/dev/null                    
 
      if [ "$5" != "1" ]; then
        Log "[TTS]"  "Playing sound ${MD5FILE}.mp3"  
        PlaySound $CNF_DATADIR/Tmp/${MD5FILE}.mp3
     fi

     if [ "$NOCACHE" == "1" ]; then
        rm -f $CNF_DATADIR/Tmp/${MD5FILE}.mp3   >>/dev/null 2>>/dev/null
        rm -f $CNF_DATADIR/Tmp/${MD5FILE}.txt   >>/dev/null 2>>/dev/null 
     else
        Log "[TTS]"  "Storing sound ${MD5FILE}.mp3 to cache"
     fi
   fi
   echo ${MD5FILE}   
}


function GoogleTTS {
   TTS=$1 
 
   MD5FILE=$(echo "$TTS" | md5sum | cut -d ' ' -f 1)
   eval $(echo "curl -A '${UA}' -o $CNF_DATADIR/Tmp/${MD5FILE}.mp3 'http://translate.google.com/translate_tts?tl=fr&q=${TTS}'" )  >>/dev/null 2>>/dev/null
   echo $( echo "$RAW_TTS" | UrlDecode)  > $CNF_DATADIR/Tmp/${MD5FILE}.txt 
 
   PlaySound $CNF_DATADIR/Tmp/${MD5FILE}.mp3     
}


function ProsodyTTS {
   TTS=$1
   VOICE=$2
  
    # Not Working
    # Need test
    return 
   
   MD5FILE=$(echo "$TTS" | md5sum | cut -d ' ' -f 1)
   # curl -s -d "$TTS" http://188.165.228.65/tts/Suzanne -o  $CNF_DATADIR/Tmp/test.mp3
    $(echo "curl -A '${UA}' -o $CNF_DATADIR/Tmp/${MD5FILE}.mp3 -s -data '${TTS}' http://188.165.228.65/tts/${VOICE}" )  >>/dev/null 2>>/dev/null
   echo $( echo "$RAW_TTS" | UrlDecode)  > $CNF_DATADIR/Tmp/${MD5FILE}.txt
            
   PlaySound $CNF_DATADIR/Tmp/${MD5FILE}.mp3
}
          
