# sistemi_operativi
registrazioni della secondo semestre di sistemi operativi convertite in:
pdf, txt, (BAD è l'output del remarkable e aspetta un intervento umano per essere corretto e salvato nel txt)

quindi io:
1. ascolto una registrazione e ogni tanto la stoppo
2. man mano scrivo quello che dice il prof poco rielaborato nel pdf sul mio remarkable 2 (landscape)

quando voglio 'salvare':
1. avvio la conversione automatica del testo dal remarkable (richiede qualche minuto)
2. apro l'app del remarkable (su windows purtroppo T_T finchè non trovo un alternativa accettabile...)
3. esporto il pdf e lo salvo su telegram nei messaggi salvati con il nome 'inputFile.pdf'
4. riapro linux e scarico il pdf da telegram
5. eseguo la 'procedura di salvataggio del pdf'
6. apro la email e scarico il testo copiando il corpo della email alla fine del file 'BAD_SO_remarkable.txt'
7. $cp BAD_SO_remarkable.txt OK_SistemiOperativi_II_registrazioni.txt
8. edito il file OK_SistemiOperativi_II_registrazioni.txt rileggendolo e
	correggendo gli errori automatici di comprensione delle lettere scritte a mano.
9. eseguo la 'procedura di salvataggio su git'

procedura di salvataggio del pdf:
1. link: https://forum.ubuntu-it.org/viewtopic.php?t=554887 per AskUbuntu
	link: https://www.pdflabs.com/docs/pdftk-cli-examples/ per una guida
2. 'Rotate an entire PDF document to 90 degrees'
	$ pdftk 'inputFile.pdf' cat 1-endeast output 'pdf_SistemiOperativi_II_semestre.pdf'
	per ruotare TUTTE le pagine da come viene 'esportato' dal remarkable
	a come voglio che venga aperto dal telefono e dal computer e da github.
3. 'Rotate the first PDF page to 90 degrees clockwise'
	pdftk 'inputFile.pdf' cat 1east 2-end output 'pdf_SistemiOperativi_II_semestre.pdf'
	per ruotare solo la prima pagina

procedura di salvataggio su github:
1. $git add .
2. $git commit -m 'COMMENTO'
	con COMMENTO che indica:
		- dove sono arrivata a scrivere nelle registrazioni:
			- data nel formato AAAA-MM-GG
			- parte1 o parte2? (pt1 pt2)
			- minuto nel formato MM:SS
		- eventuali problemi nelle registrazioni
		- eventuali altri problemi
3. $git push

##qui voglio salvare anche

esercizi per concorrenza, parte generale, corretti dal prof, provati da me o comunque cose che voglio tenere anche se mi dovesse morire il computer domani...
