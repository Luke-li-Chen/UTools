using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace UTool_CS
{
    public class Class1
    {
        public bool Is64bit()
        {
            if (Environment.Is64BitProcess)
            {
                return true;
            }
            return false;
        }
    }

    
}
