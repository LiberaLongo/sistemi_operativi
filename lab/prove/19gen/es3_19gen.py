import os, sys, shutil

def copy_object(source, dst):
    if os.path.isfile(source):
        shutil.copy(source, dst)
    else: 
        os.mkdir(os.path.join(dst, os.path.basename(source)))
        for f in os.listdir(source):
            copy_object(os.path.join(source, f), os.path.join(dst, os.path.basename(source)))

def merge(a, b, dst):
    A = os.listdir(a)
    B = os.listdir(b)
    for e in A:
        if e in B:
            if(os.path.isdir(os.path.join(a, e))):
                os.mkdir(os.path.join(dst, e))
                merge(os.path.join(a, e), os.path.join(b, e), os.path.join(dst, e))
            else:
                f1 = open(os.path.join(a, e), 'r')
                f2 = open(os.path.join(b, e), 'r')
                file_dst = open(os.path.join(dst, e), 'w')
                file_dst.write(f1.read() + f2.read())
                f1.close()
                f2.close()
                file_dst.close()
            B.remove(e)
        else:
            copy_object(os.path.join(a, e), dst)
    for e in B:
        copy_object(os.path.join(b, e), dst)

def main():
    if len(sys.argv) < 4:
        print("Not enough arguments")
        return
    
    dir1 = sys.argv[1]
    dir2 = sys.argv[2]
    dst = sys.argv[3]
    
    merge(dir1, dir2, dst)
    print("Done merging!")

if __name__ == "__main__":
    main()
