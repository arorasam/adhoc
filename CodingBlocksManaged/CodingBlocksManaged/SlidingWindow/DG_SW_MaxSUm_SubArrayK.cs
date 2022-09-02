using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodingBlocksManaged.SlidingWindow
{
    internal class DG_SW_MaxSUm_SubArrayK
    {
        public int[] MaxSum_SubArray_SizeK(int[] nums, int k)
        {
            int maxSum = -1;
            int currSum = 0;
            // Sliding window tracking variables
            int windowStart = 0;
            int[] window = new int[k];
            for (int i = 0; i < nums.Length - k; i++)
            {
                currSum += nums[i];
                if (i >= k - 1) // we have reached the end of SW
                {
                    if (currSum > maxSum)
                    {
                        window[0] = windowStart;
                        window[1] = i;
                        maxSum = currSum;
                    }

                    // Slide window by dropping the earliest element.
                    currSum -= nums[windowStart];
                    windowStart++;
                }
            }

            return window;
        }
    }
}
