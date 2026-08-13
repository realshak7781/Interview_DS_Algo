// TIme : O(N*N*2^N)
// SPACE : O(N*2^N)


class Solution {
    public int shortestPathLength(int[][] graph) {
        int n=graph.length;
        int targetMask = (1 << n) - 1;

        boolean[][] vis=new boolean[n][1 << n];
        Queue<int[]> q = new ArrayDeque<>();

        for(int i=0;i<n;i++){
            int initialMask=(1<<i);
            q.offer(new int[]{i, initialMask});
            vis[i][initialMask]=true;
        }

        int steps=0;

        while(!q.isEmpty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                int[] curr = q.poll();
                int node=curr[0];
                int mask=curr[1];

                if(mask==targetMask) return steps;

                for(int neigh : graph[node]){
                    int nextMask = mask | (1 << neigh);

                    if(!vis[neigh][nextMask]){
                        vis[neigh][nextMask]=true;
                        q.offer(new int[]{neigh,nextMask});
                    }
                }
            }

            steps++;
        }


        return -1;
    }
}
