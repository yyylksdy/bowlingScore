int score(int x[12][4])
{
	 int j;
	    for (j = 1; j <= 10; j++)
	    {
	        if (x[j][0] == 10)
	        {
	            if (x[j + 1][0] == 10)
	                x[j][2] = 20 + x[j + 2][0];
	            else
	                x[j][2] = 10 + x[j + 1][0] + x[j + 1][1];
	        }
	        else
	        {
	            if (x[j][0] + x[j][1] == 10)
	                x[j][2] = 10 + x[j + 1][0];
	            else
	                x[j][2] = x[j][0] + x[j][1];
	        }
	    }

	    x[1][3] = x[1][2];
	    for (j = 2; j <= 10; j++)
	        x[j][3] = x[j - 1][3] + x[j][2];
   return x[10][3];
}
