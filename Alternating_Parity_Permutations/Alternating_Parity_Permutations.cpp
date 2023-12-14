vector<int> merge( vector<int>A , vector<int>B )
 {
     int i = 0 ; int j = 0 ; 
     vector<int>t; 
     for( int k = 1 ; k <= A.size() + B.size() ; k++ )
     {
        if( k&1 && i < A.size() )
          t.push_back(A[i++]);
        else if( k%2 == 0 && j < B.size() )
          t.push_back(B[j++]);
     }
     return t ; 
 }

vector<vector<int>>alternatingparityPermutation(int N)
{
      vector<vector<int>>res; 
      vector<int>E , O ; 
     
      // break the original permuation in to two parts then
      // use nextpermuation in nested style to get all resutls
      // then sort the final array 
      // when no of element is odd then first element should be always odd 
      // in this case only merge( O , E ) is possible 
    
      for( int i = 1 ; i <= N ; i++ )
      {
          if( i&1 )O.push_back(i);
          else E.push_back(i);
      }


      do
      {
             do
             {
                            res.push_back( merge( O , E ) ); 
                  if(N%2==0)res.push_back( merge( E , O ) );  
             }
             while( next_permutation( O.begin() , O.end() ) );
      }
      while( next_permutation( E.begin() , E.end() ) );

      sort( res.begin() , res.end() ); 
      return res; 
}