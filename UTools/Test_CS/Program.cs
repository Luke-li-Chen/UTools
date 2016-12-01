using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UTool_CS;

namespace Test_CS
{
    class Program
    {
        static void Main(string[] args)
        {
            Class1 c = new Class1();
            if(c.Is64bit())
            {
                Console.WriteLine("True");
            }
            else
            {
                Console.WriteLine("False");
            }
        }
    }
}
