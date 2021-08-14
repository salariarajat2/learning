 for (int j = 0; j < N; j++)
    {
        for (int i = N - 1; i >= 0; i--)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
    
    
      
    // First rotation
    // with respect to main diagonal
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
        
        
         // Second rotation
    // with respect to middle column
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N / 2; ++j)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][N - j - 1];
            arr[i][N - j - 1] = temp;
        }
        
        
         // First rotation
    // with respect to Secondary diagonal
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N - i; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[N - 1 - j][N - 1 - i];
            arr[N - 1 - j][N - 1 - i] = temp;
        }
    }
    
    
     // Second rotation
    // with respect to middle row
    for(int i = 0; i < N / 2; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[N - 1 - i][j];
            arr[N - 1 - i][j] = temp;
        }
    }
