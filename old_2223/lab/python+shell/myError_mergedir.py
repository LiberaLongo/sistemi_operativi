#!usr/bin/env python3
#esercizio 2023 01 19 (gennaio)

#guide seguite
# directory https://www.programiz.com/python-programming/directory
# argc argv https://realpython.com/python-command-line-arguments/
# copy https://www.geeksforgeeks.org/copy-all-files-from-one-directory-to-another-using-python/
# append https://stackoverflow.com/questions/59735588/append-to-file-only-if-it-already-exists

import os, sys, shutil

def append(src_name, dest_name):
	#open
	src_fd = open(src_name, 'r');
	dest_fd = open(dest_name, 'a+');
	#append
	dest_fd.write(src_fd.read());
	#close
	src_fd.close();
	dest_fd.close();

def merge(A_dir, B_dir, merge_dir):
	"""merge a and b into c."""

	'''	#mkdir if not exists
		if not os.path.exists(merge_dir):
			os.mkdir(merge_dir);
			print('mkdir', merge_dir);
	'''
	#se merge esiste
	if os.path.exists(merge_dir):
		confirm = input('\'' + merge_dir + '\' already exists, I have to delete it, can I? (yes/no) ');
		#se confermo la rimozione
		if confirm == 'yes' :
			shutil.rmtree(merge_dir); #shutil.copytree vuole che la directory non esista già
			print('rm -rf', merge_dir);
		else: return;

	print('ls', A_dir, ':\n\t', os.listdir(A_dir));
	#merging
	#shutil.copytree(src, dest, copy_method (optional))
	shutil.copytree(A_dir, merge_dir);
	#shutil.copytree(B_dir, merge_dir) #se ci fossero file comuni darebbe errore!

	contentB = os.listdir(B_dir);
	print('ls', B_dir, ':\n\t', contentB);

	for file in contentB:

		path_read_file = os.path.join(B_dir, file)
		path_in_merge = os.path.join(merge_dir, file);

		file_or_dir = 'file' if os.path.isfile(path_read_file) else ' dir';
		print('\t\t', file_or_dir, ':', file, end='\t\t');

		if os.path.exists(path_in_merge):
			print('  exists   --> append');
			if os.path.isfile(path_read_file) and os.path.isfile(path_in_merge):
				append(path_read_file, path_in_merge);
			else:
				print('ERROR: I can\'t append two subdirectories! T_T')
		else:
			print('not exists --> copy');
			if os.path.isfile(path_read_file):
				shutil.copy(path_read_file, merge_dir);	
			else:
				shutil.copytree(path_read_file, path_in_merge); #errore pk mergedir esiste						

	#list the result
	print('ls', merge_dir, ':\n\t', os.listdir(merge_dir));

def main():
	#no arguments
	if (len(sys.argv) != 4):
		print("\t\tBad usage, i need 3 parameters:");
		print("\t\tA (argv1), and B (argv2): directories to merge");
		print("\t\tC (argv3): directory to put stuff you want to merge");
		dir_A = input("insert A (dir): ");
		dir_B = input("insert B (dir): ");
		dir_C = input("insert C (merge dir): ");
	#arguments
	else:
		print ('\t\tNumber of arguments:', len(sys.argv), 'arguments.');
		print ('\t\tArgument List:', str(sys.argv));
		dir_A = sys.argv[1];
		dir_B = sys.argv[2];
		dir_C = sys.argv[3];
	print();
	#merge
	merge(dir_A, dir_B, dir_C);	

if __name__ == "__main__":
	main();

