# karotz-app

## Divers
### Description
Nouveau fichier `tts.inc` avec une autre fonction de tts pour palier au problème de tts openkarotz.

### Installation
Télécharger le fichier `tts.inc` et le mettre dans `/usr/www/cgi-bin/` sur le lapin à la place de celui d'origine.
garder une copie de l'ancien est préférable.

## ProgTV
### Description
application pour openkarotz permettant de dicter le programme TV.

### Installation
Pour l'installaiton télécharger le fichier d'intallation correspondant à l'appli voulue sur le karotz depuis le répertoire install.
Placez le ou vous le souhaitez sur le karotz puis executer le :

```
bash <nom du fichier>
```

### Documentation
Le système s'utilise comme l'api standard du karotz via des requettes HTTP

Toute les commandes seront du type:

```
http://<ip_lapin>/cgi-bin/progtv?parametre=valeur
```

Paramètre disponible :
* dolist (0)
  * retourne la liste des chaine disponible (0 ou 1)
    * exemple : `http://<ip_lapin>/cgi-bin/progtv?dolist=1`
* listechaine (null)
  * liste des chaines dont on souhaite avoir le programme (liste séparé par des _)
    * exemple : `http://<ip_lapin>/cgi-bin/progtv?listechaine=TF1_M6_FRANCE 2_FRANCE 3_W9`
* voix (margaux)
  * permet de changer la voix par defaut du tts
    * exemple : `http://<ip_lapin>/cgi-bin/progtv?listechaine=TF1_M6_FRANCE 2_FRANCE 3_W9&voix=julie`
* nocache (0)
  * permet de ne pas mettre ne cache les textes
    * exemple : `http://<ip_lapin>/cgi-bin/progtv?listechaine=TF1_M6_FRANCE 2_FRANCE 3_W9&nocache=1`

## Meteo
### Description
application pour openkarotz permettant de dicter la meteo du jours

ATTENTION LE SCRIPT N'EST PAS ENCORE FONCTIONNEL
