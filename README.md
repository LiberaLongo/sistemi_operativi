# sistemi_operativi

registrazioni della secondo semestre di sistemi operativi convertite in:
pdf, txt, (BAD è l'output del remarkable e aspetta un intervento umano per essere corretto e salvato nel txt)

quindi io:
1. ascolto una registrazione e ogni tanto la stoppo
2. man mano scrivo quello che dice il prof poco rielaborato nel pdf sul mio remarkable 2 (landscape)

## file

### file principali

quindi troverete vari tipi di file:
i file che cominciano con:
- 'pdf' (PDF) sono quello che scrivo io a mano (ascoltando la registrazione).
- 'BAD' (TXT) sono la conversione automatica in testo fatta dal remarkable di ciò che è stato scritto a mano
- 'OK'  (TXT) sono la rilettura e la correzzione da parte di un umano (anche io)
	di ciò che è stato scritto in 'BAD' rileggendo 'pdf'
notate che se qualcuno ha riletto e corretto BAD in OK allora alla versione successiva
BAD avrà la prima parte uguale a OK e una parte sotto ANCORA DA SISTEMARE
questa parte è riconoscibile velocemente dal fatto che il remarkable mi invia le righe scritte
intermezzate da con una riga in mezzo completamente vuota.
che si chiede di eliminare la riga vuota durante la revisione!

e questi sono i file principali.

# REVISIONE

A cosa serve la revisione del pdf nei file txt?
serve per:
- ripasso (leggere OK e correggerlo serve anche per rileggere tutto)
- rendere più semplici modifiche SUCCESSIVE
	(che copiano tranquillamente, ma NON DEVONO modificare i FILE PRINCIPALI!
  tra le quali: schemi, riassunti, tutto ma sfruttando meglio le righe...

che regole vi chiedo di rispettare durante la revisione:
- si chiede di eliminare la riga vuota durante la revisione.
- si chiede di lasciare i separatori di pagina (righe con '• • • ').
- si chiede di lasciare gli a capo delle altre righe
	in modo che chi fa la revisione del 'pdf' e di 'BAD' si ritrovi facilmente
	con le pagine e le righe che iniziano con le stesse parole!
- si chiede nella revisione di correggere SOLTANTO la comprensione delle parole,
	senza riassumere, modificare la struttura della frase, o altre modifiche...
	insomma ricordando sempre che  ''deve RIMANERE tutto quello che dice il prof''
	quindi 'OK' è il formato TXT di quello che cè scritto in 'pdf'!
	se il remarkable avesse fatto tutta la conversione correttamente senza aver fatto errori
	la lettura e modifica si limiterebbero al solo cancellare le righe vuote!
	(esempio di errori notati: aver letto una 'a' come 'o-', una 'b' come una 'l', 'pdf' come 'golf'...
	aver tradotto in italiano parole che dovevano rimanere in inglese
	come 'systemcall' diventata 'systemicall' o 'sistemicall'...)
	ed eventualmente aggiungere le tabulazioni per le domande degli studenti che occupano più righe.

se si vogliono fare questo tipo di operazioni:
	- riassumere
	- modificare la riga
	- modificare parole o l'ordine delle parole
	- modificare la struttura della frase
	si prega di leggere la struttura degli schemi
	e di copiare 'OK' o 'BAD' a seconda in un NUOVO file (TXT) modificando SOLO il nuovo file.
	lasciando inalterati i 'file principali'.

### file riassuntivi / schematici

Oltre a questi possono esserci file chiamati
'schema_DATA(registrazione)_slideSLIDE_AUTORE_DATA(schema)' in formato immagine (PNG) o (PDF)
(
	ad esempio:
  'schema_2022-02-25_slide00-intro.pdf_llibera_2022-12-09.png'
  ovvero lo schema riguardante la registrazione del 2022-02-25 ( DATA(registrazione) = 2022-02-25 )
  in cui il prof spiegava mostrandoci la slide 00-intro.pdf    ( SLIDE = 00-intro.pdf )
  schema fatto da llibera (ovvero Libera Longo, me)            ( AUTORE = llibera )
  in data anno 2022 mese 12 (dicembre) giorno 9                ( DATA(schema) = 2022-12-09 )
)
in modo da poter riassumere e schematizzare il contenuto del 'pdf' principale.
questi devono essere salvati nella cartella 
NOTA che però che qualsiasi riassunto ha senso solo nella misura
in cui si possa approfondire rileggendo il 'pdf' principale
che quindi non va mai cancellato!

## qui voglio salvare anche

esercizi per concorrenza, parte generale, corretti dal prof, provati da me o comunque cose che voglio tenere anche se mi dovesse morire il computer domani...

## procedura di salvataggio 

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
		$cd IIsem-BACKUP
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

e se volessi ruotare solo certe pagine e non tutte?
	'Rotate the first PDF page to 90 degrees clockwise'
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

