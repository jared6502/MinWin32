@echo off
echo Building image...
ImageFileBuilder init.bin 32256 k.bin
ImageFileBuilder floppy.img 1474560 boot.bin k.bin emptyfs.bin emptydir.bin emptyclusters.bin
echo Done.
