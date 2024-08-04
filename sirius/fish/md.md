Google "SPOJ PSTRING" or "SPOJ 704". You can do a DP, 

F[i][j] means that if you have processed the first i symbols of the string S and the largest prefix of the string T is j, what is the minimal number of symbols to remove.

You have to preprocess the value of R[i][j], means that if there is a i-prefix of T (lets call it G), what is the largest suffix of G+j (j is char) that is the prefix of T can be obtained. Prefix function or hashes will do. You will get O(|S|*|T|) complexity for the problem ..
