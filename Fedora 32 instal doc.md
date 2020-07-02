# Fedora 32 installation sur DD externe


## ***PREPARATION DE LA CLEF BOOTABLE***

 - Téléchargez Fedora Media Writer via cette commande `sudo dnf install
   liveusb-creator`
   
   Pour windows vous pouvez le télécharger ici
   https://mbriza.fedorapeople.org/liveusb-creator.zip
   
   (Liens trouvé ici :
   https://developers.redhat.com/blog/2016/04/26/fedora-media-writer-the-fastest-way-to-create-live-usb-boot-media/)
 - Lancez FMW en su via la commande `Mediawriter` ou directement via `liveusb-creator.exe`
 - Choisir l'option `Fedora Workstation 32` si c'est la version la plus récente sinon choisir l'option `Image personnalisée`
 - Si vous n'installez pas la dernière version, choisir l'iso préalablement téléchargé
 - Cliquer sur `Création du Live USB`
 - Choisir où installer et lancer l'écriture (Si vous lancez la dernière version et que vous n'avez donc pas préalablement télécharger l'iso, le logiciel va le télécharger pour vous il faudra donc attendre la fin du téléchargement pour lancer l'installation)


## ***INSTALLER FEDORA 32 SUR LE DD externe***

 - Redémarrer le pc sur le menu BOOT
 - choisir de démarrer sur la clef avec fedora
 - choisir `Start Fedora-Workstation-Live 32`
 - Une fois fedora lancé, choisissez `Install to Hard Drive`
 - Choisir la langue d'installation (Par defaut English -> English (United States)) puis continuer (Cela peut prendre un peu de temps, ne pas marteler le bouton continuer)
 - Dans la sous partie `System` cliquer sur `Installation Destination`
 - Sur la nouvelle page, choisir le disque dur sur lequel vous voulez installer fedora
 - Dans la sous partie `Storage Configuration` Cliquer sur `Automatic` puis appuyer sur le bouton `Done` tout en haut de la page
 - une pop up va apparaitre expliquant l'espace requis pour s'installer, cliquer sur `Reclaim space`
 - une nouvelle pop up apparait pour vous demandez ou trouver l'espace requis, cliquez sur `Delete all` en bas à droite de la pop up puis `Reclaim space` 
 - Si tout se passe bien vous devriez revenir sur la page de base, cliquez sur `Begin installation`
 - Une fois l'installation terminé cliquez sur `Quit` en bas de la fenêtre
 - Redémarrer le pc sur le DD externe et choisissez `Workstation Edition`
 - Félicitation vous pouvez maintenant paramétrer et profiter de votre Fedora !
 ![enter image description here](https://media.giphy.com/media/xT0xezQGU5xCDJuCPe/giphy.gif)
