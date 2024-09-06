int choice(Character c1 , Character c2){

        if(c1==null || c2==null){
            return 0;
        }
        int x1 = (c1-'A')/6;
        int y1 = (c1-'A')%6;

        int x2 = (c2 -'A')/6;
        int y2 = (c2 -'A')%6;

        return Math.abs(x1-x2) + Math.abs(y1-y2);
    }
    int solve( String word , int i , Character f1 , Character f2 , Integer dp[][][]){
        if(i>=word.length()){
            return 0;
        }
        int i1 = f1==null ?0 :f1;
        int i2 = f2==null ?0 :f2;
        if(dp[i][i1][i2]!=null){
            return dp[i][i1][i2];
        }
        int c1 = choice(word.charAt(i) , f1) + solve(word,i+1,word.charAt(i) , f2 , dp);
        int c2 = choice(word.charAt(i) , f2) + solve(word,i+1,f1 , word.charAt(i) , dp);

        return dp[i][i1][i2] = Math.min(c1,c2);
    }
    public int minimumDistance(String word) {
        
        Integer dp[][][] = new Integer[word.length()][256][256];

        return solve(word,0,null,null,dp);
    }