public class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        List<String> res = new LinkedList<>(); 
        Trie root = new Trie();
        for(String s: words){
             if(s.length() == 0) continue; 
             Trie p = root;
             for(char c: s.toCharArray()){
                 if(p.next[c - 'a']==null) p.next[c - 'a'] = new Trie();  
                 p = p.next[c - 'a']; 
             }
             p.word = s; 
        }
        for(String s: words) 
            if(dfs(s, root, 0, root)) res.add(s); //check each word using the tree
        return res;
    }
    private boolean dfs(String s, Trie t, int p, Trie root){
        if(p == s.length()) return t.word != null && !t.word.equals(s); 
        if(t.next[s.charAt(p) - 'a'] == null) return false; 
        if(t.next[s.charAt(p) - 'a'].word!=null && dfs(s, root, p + 1, root)) return true; 
        return dfs(s, t.next[s.charAt(p) - 'a'] ,p + 1, root); 
    }
    class Trie{
        Trie[] next = new Trie[26];
        String word = null; 
    }
}