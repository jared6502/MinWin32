@echo off
echo Building image...
ImageFileBuilder floppy.img 1474560 boot.bin init.bin emptyfs.bin emptydir.bin emptyclusters.bin
echo Done.
