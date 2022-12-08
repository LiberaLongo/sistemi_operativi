# sistemi_operativi
registrazioni della secondo semestre di sistemi operativi convertite in:
pdf, txt, (BAD è l'output del remarkable e aspetta un intervento umano per essere corretto e salvato nel txt)

quindi io:
1. ascolto una registrazione e ogni tanto la stoppo
2. man mano scrivo quello che dice il prof poco rielaborato nel pdf sul mio remarkable 2 (landscape)

quando voglio 'salvare':
1. avvio la conversione automatica del testo dal remarkable (richiede qualche minuto...)
2. scelgo tra: salvare un file 'di backup' o il 'file intero contenente tutte le lezioni fin'ora'

	se il file è di tutte le lezioni: 
	il file 'OK' è 'OK_SistemiOperativi_II_registrazioni.txt'
	il file 'BAD' è 'BAD_SO_remarkable.txt'

	se il file è di backup (una lezione / una parte di una lezione (prima o dopo la pausa)):
	il file 'OK' è 'OK_DATA.txt'
	il file 'BAD' è 'BAD_DATA.txt'
	1. in base alla data della lezione apro la cartella corrispondente:
		$cd secondo_semestre_backup_separate/
		$ls
	2. scelgo se creare una cartella nuova (con data in formato ANNO-MESE-GIORNO)
		$mkdir DATA 
	   oppure cambiare directory entrando nella dir vecchia
		$cd DATA

dopo aver capito come sono chiamati i file ... faccio:
1. eseguo la 'procedura di salvataggio del pdf'
2. apro la email e scarico il testo copiando il corpo della email alla fine del file 'BAD' e poi
		$cp 'BAD' 'OK'
4. edito il file 'OK' rileggendolo correggendo gli errori
	automatici di comprensione delle lettere scritte a mano.
	in questo modo:
	- il file 'BAD' contiene (ciò che è stato corretto PRIMA) e ciò che DEVE ancora essere CORRETTO.
	- il file 'OK' contiene tutto ciò che era in 'BAD' ma già corretto da un umano.
5. eseguo la 'procedura di salvataggio su git'

procedura di salvataggio del pdf:
1. link: https://forum.ubuntu-it.org/viewtopic.php?t=554887 per AskUbuntu
	link: https://www.pdflabs.com/docs/pdftk-cli-examples/ per una guida
2. 'Rotate an entire PDF document to 90 degrees'
		$pdftk 'inputFile.pdf' cat 1-endeast output 'pdf_SistemiOperativi_II_semestre.pdf'
	per ruotare TUTTE le pagine da come viene 'esportato' dal remarkable
	a come voglio che venga aperto dal telefono e dal computer e da github.
3. 'Rotate the first PDF page to 90 degrees clockwise'
		$pdftk 'inputFile.pdf' cat 1east 2-end output 'outputFileNAME.pdf'
	per ruotare solo la prima pagina
NOTA che 'pdf_SistemiOperativi_II_semestre.pdf' é il nome per il pdf di tutte le lezioni.
	 ma è bene anche salvare pdf intermedi delle lezioni prese separatamente (nelle cartelle a loro dedicate),
	 sia per backup sia per eventuali successive elaborazioni, riassunti, txt di tutto... .
	 potete fare 'fork' e 'pull request' se volete proporre modifiche o altre elaborazioni di ciò che ho scritto io.
	 oppure direttamente a: https://github.com/csunibo/sistemi-operativi.git di qui questo repository
	 farà un contributo una volta che il lavoro è a buon punto (prima è comunque visibile tramite un link).

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

## qui voglio salvare anche

esercizi per concorrenza, parte generale, corretti dal prof, provati da me o comunque cose che voglio tenere anche se mi dovesse morire il computer domani...
