# Fedora 29 installation sur DD externe

***Si vous avez déja une clef bootable disponible vous pouvez directement passer à la partie "Installer fedora 29 sur le DD externe***

## ***TELECHARGER L'ISO :***

 - Vous pouvez trouver les iso ici : https://archive.fedoraproject.org/pub/archive/fedora/linux/releases/29/Workstation/x86_64/iso/
 - Téléchargez [Fedora-Workstation-Live-x86_64-29-1.2.iso](https://archive.fedoraproject.org/pub/archive/fedora/linux/releases/29/Workstation/x86_64/iso/Fedora-Workstation-Live-x86_64-29-1.2.iso)


## ***PREPARATION DE LA CLEF BOOTABLE***

 - Téléchargez Fedora Media Writer via cette commande `sudo dnf install
   liveusb-creator`
   
   Pour windows vous pouvez le télécharger ici
   https://mbriza.fedorapeople.org/liveusb-creator.zip
   
   (Liens trouvé ici :
   https://developers.redhat.com/blog/2016/04/26/fedora-media-writer-the-fastest-way-to-create-live-usb-boot-media/)
 - Lancez FMW en su via la commande `Mediawriter` ou directement via `liveusb-creator.exe`
 - Choisir l'option `Image Personnalisée`
 - Choisir l'iso préalablement téléchargé
 - Choisir ou installer et lancer l'écriture


## ***INSTALLER FEDORA 29 SUR LE DD externe***

 - Redémarrer le pc sur le menu BOOT
 - choisir de démarrer sur la clef avec fedora
 - choisir `Start Fedora-Workstation-Live 29`
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
 ![enter image description here](https://media.giphy.com/media/fdyZ3qI0GVZC0/giphy.gif)
