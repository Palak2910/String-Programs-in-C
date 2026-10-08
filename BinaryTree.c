void dfs(struct TreeNode* root, char* path, char** result, int* returnSize) {
    if (root == NULL)
        return;

    char current[1000];

    if (path[0] == '\0')
        sprintf(current, "%d", root->val);
    else
        sprintf(current, "%s->%d", path, root->val);

    if (root->left == NULL && root->right == NULL) {
        result[*returnSize] = malloc(strlen(current) + 1);
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    dfs(root->left, current, result, returnSize);
    dfs(root->right, current, result, returnSize);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char** result = malloc(100 * sizeof(char*));
    *returnSize = 0;

    dfs(root, "", result, returnSize);

    return result;
}
