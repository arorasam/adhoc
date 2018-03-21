using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodingBlocksManaged
{
    class Program
    {
        static void Main(string[] args)
        {
        }

        static int ExtractInt(string str, int index, int length)
        {
            return Int32.Parse(str.Substring(index, length));
        }

        static bool CheckSumString(string s, int size, int index)
        {
            if (size < 3)
                return false;

            // Skip handling 0 for now

          
            // Parse last number 
            int last = ExtractInt(s, index, size);
            
            // Parse second last number
            int secondlast1 = ExtractInt(s, index - size, size);
            int secondlast2 = ExtractInt(s, index - size, size - 1);

            // Parse third last number
            int thirdlast1 = ExtractInt(s, index - size - size, size);
            int thirdlast2 = ExtractInt(s, index - size - size, size - 1);
            int thirdlast3 = ExtractInt(s, index - size - size, size - 2);

            // check if they add up?
            if( last == (secondlast1 + thirdlast1) || 
                last == (secondlast2 + thirdlast2))  
                last == (secondlast2 + thirdlast3))


            return false;
        }

        static void Exec_CheckSumString()
        {
            var testCount = Int32.Parse(Console.ReadLine());
            for(int i = 0; i < testCount; i++)
            {
                string testCase = Console.ReadLine();
                Console.WriteLine(CheckSumString(testCase, testCase.Length - 2, testCase.Length - 1) ? "true" : "false");
            }
        }
    }
}
