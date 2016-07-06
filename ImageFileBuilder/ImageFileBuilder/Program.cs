using System;
using System.Collections.Generic;
using System.Text;

namespace ImageFileBuilder
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args == null) return;
            if (args.Length < 0) return;

            if (args.Length < 2)
            {
                Console.WriteLine("Usage: ImageFileBuilder <output file> <image size> <file name> <file name> ... <file name>");
                Console.WriteLine("If no files are specified, the image will be initialized with zeros");
                Console.WriteLine("If the files are larger than the desired image size, the image will grow to match.");
                Console.WriteLine("");
                return;
            }

            bool result;
            UInt64 size;

            using (System.IO.FileStream outfile = new System.IO.FileStream(args[0], System.IO.FileMode.Create))
            {

                result = UInt64.TryParse(args[1], out size);

                if (!result)
                {
                    //first item was not a number
                    Console.WriteLine("Size not specified.");
                    return;
                }

                //nothing else specified, create new file initialized to null
                if (args.Length < 3)
                {
                    for (UInt64 i = 0; i < size; i++)
                    {
                        outfile.WriteByte(0x00);
                    }
                }
                else
                {
                    UInt64 byteswritten = 0;

                    for (int i = 2; i < args.Length; i++)
                    {
                        using (System.IO.FileStream infile = new System.IO.FileStream(args[i], System.IO.FileMode.Open))
                        {
                            int b = 0;
                            while (b != -1)
                            {
                                b = infile.ReadByte();
                                if (b != -1)
                                {
                                    outfile.WriteByte((byte)b);
                                    byteswritten++;
                                }
                            }
                        }
                    }

                    if (byteswritten < size)
                    {
                        for (UInt64 i = 0; i < size - byteswritten; i++)
                        {
                            outfile.WriteByte(0x00);
                        }
                    }
                }
            }
        }
    }
}
