int a[MAXN][MAXN];//�������
int x[MAXN];//�⼯
bool free_x[MAXN];//����Ƿ��ǲ�ȷ���ı�Ԫ
inline int lcm(int a, int b) {
    return a / __gcd(a, b) * b;//�ȳ���˷����
}
//(-2��ʾ�и������⣬���������⣬-1��ʾ�޽⣬0��ʾΨһ�⣬����0��ʾ����⣬���������ɱ�Ԫ�ĸ���)
//��equ�����̣�var����Ԫ�������������Ϊequ,�ֱ�Ϊ0��equ-1,����Ϊvar+1,�ֱ�Ϊ0��var.
int Gauss(int equ, int var){
    int i,j,k;
    int max_r;// ��ǰ���о���ֵ������.
    int col;//��ǰ�������
    int ta, tb;
    int LCM;
    int temp;
    int free_x_num;
    int free_index;
    for(i = 0; i <= var; ++i) {
        x[i] = 0;
        free_x[i] = true;
    }
    //ת��Ϊ������.
    col = 0; // ��ǰ�������
    for(k = 0; k < equ && col < var; ++k, ++col) {
		// ö�ٵ�ǰ�������.
        max_r = k;
        for (i = k + 1; i < equ; ++i) {
            if(abs(a[i][col]) > abs(a[max_r][col])) max_r = i;
        }
        if (max_r != k){
		// j = k?
            for(j = col; j < var + 1; ++h) swap(a[k][j], a[max_r][j]);
        }
        if (a[k][col] == 0) {
		// ˵����col�е�k������ȫ��0�ˣ�����ǰ�е���һ��.
            --k;
            continue;
        }
        for (i = k + 1; i < equ; ++i) {
		// ö��Ҫɾȥ����.
            if (a[i][col] != 0) {
                LCM = lcm(abs(a[i][col]), abs(a[k][col]));
                ta = LCM / abs(a[i][col]);
                tb = LCM / abs(a[k][col]);
                if (a[i][col] * a[k][col] < 0) tb = -tb;//��ŵ���������
                for (j = col; j < var + 1; ++j) {
                    a[i][j] = a[i][j] * ta - a[k][j] * tb;
                }
            }
        }
    }
    // 1. �޽�����: ������������д���(0, 0, ..., a)��������(a != 0).
    for (i = k; i < equ; ++i) { 
	// �����������˵�����Ҫ�ж���Щ�����ɱ�Ԫ����ô�����б任�еĽ����ͻ�Ӱ�죬��Ҫ��¼����.
        if (a[i][col] != 0) return -1;
    }
    // 2. ���������: ��var * (var + 1)���������г���(0, 0, ..., 0)�������У���˵��û���γ��ϸ����������.
    // �ҳ��ֵ�������Ϊ���ɱ�Ԫ�ĸ���.
    if (k < var) {
    // ���ȣ����ɱ�Ԫ��var - k��������ȷ���ı�Ԫ������var - k��.
        for (i = k - 1; i >= 0; i--) {
        // ��i��һ��������(0, 0, ..., 0)���������Ϊ�����������ڵ�k�е���equ��.
            // ͬ������i��һ��������(0, 0, ..., a), a != 0��������������޽��.
            free_x_num = 0; // �����жϸ����еĲ�ȷ���ı�Ԫ�ĸ������������1�������޷���⣬������ȻΪ��ȷ���ı�Ԫ.
            for (j = 0; j < var; ++j) {
                if (a[i][j] != 0 && free_x[j]) ++free_x_num, free_index = j;
            }
            if (free_x_num > 1) continue; // �޷�����ȷ���ı�Ԫ.
            // ˵����ֻ��һ����ȷ���ı�Ԫfree_index����ô���������ñ�Ԫ���Ҹñ�Ԫ��ȷ����.
            temp = a[i][var];
            for (j = 0; j < var; ++j) {
                if (a[i][j] != 0 && j != free_index) temp -= a[i][j] * x[j];
            }
            x[free_index] = temp / a[i][free_index]; // ����ñ�Ԫ.
            free_x[free_index] = 0; // �ñ�Ԫ��ȷ����.
        }
        return var - k; // ���ɱ�Ԫ��var - k��.
    }
    // 3. Ψһ������: ��var * (var + 1)�����������γ��ϸ����������.
    for (i = var - 1; i >= 0; --i) {
        temp = a[i][var];
        for (j = i + 1; j < var; ++j) {
            if (a[i][j] != 0) temp -= a[i][j] * x[j];
        }
        if (temp % a[i][i] != 0) return -2; // ˵���и������⣬����������.
        x[i] = temp / a[i][i];
    }
    return 0;
}
//gauss��򷽳������
void gauss() {
	tot = ok = 0;
	for (int i = 60; i >= 0; --i) {
		int j = tot + 1;
		while (!(p[i] & a[j]) && j <= n)	++j;
		if (j == n + 1)	continue;
		++tot;
		swap(a[tot], a[j]);
		for (int k = 1; k <= n; ++k)
			if (k != tot && (a[k] & p[i]))	
				a[k] ^= a[tot];
	}
	if (tot != n)	ok = 1;//0
}
//gauss ȡģ
void gauss(){ 
	int n = 11;
    for(int i = 1; i <= n; ++i) {  
        int k;
        for (k = i; k <= n; ++k)	if (a[k][i])	break;
		if (k != i)	for(int j = 1; j <= n + 1; ++j)	swap(a[k][j], a[i][j]);  
		for (int j = 1; j <= n; ++j) {
			if (j != i && a[j][i]) {
				LL t = a[j][i] * P(a[i][i], M - 2) % M;
				for (k = 1; k <= n + 1; ++k)	a[j][k] = (a[j][k] - t * a[i][k] % M + M) % M;
			}
		}
    }  
	for (int i = 1; i <= n; ++i)	b[i] = a[i][n + 1] * P(a[i][i], M - 2) % M;
}  
