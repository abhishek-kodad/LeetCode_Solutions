class Solution {
public:
    vector<int> getArray(ListNode* head){
        vector<int> ans;
        while(head){
            ans.push_back(head->val);
            head=head->next;
        }
        return ans;
    }
    TreeNode* createBinarySearchTree(TreeNode* root,vector<int>& arr,int s,int e){
        if(s>e) return NULL;
        int mid=s+(e-s)/2;
        root=new TreeNode(arr[mid]);
        root->left=createBinarySearchTree(root->left,arr,s,mid-1);
        root->right=createBinarySearchTree(root->right,arr,mid+1,e);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root=NULL;
        vector<int> arr=getArray(head);
        return createBinarySearchTree(root,arr,0,arr.size()-1);
    }
};