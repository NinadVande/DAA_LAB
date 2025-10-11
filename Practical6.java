import java.util.Scanner;

public class Practical6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] keys = new int[n + 1];
        double[] p = new double[n + 1];
        double[] q = new double[n + 1];
        double[][] e = new double[n + 1][n + 1];
        double[][] w = new double[n + 1][n + 1];
        System.out.println("Enter keys Element:");
        for (int i = 1; i <= n; i++) keys[i] = sc.nextInt();
        System.out.println("Enter Prob of successfull search:");
        for (int i = 1; i <= n; i++) p[i] = sc.nextDouble();
        System.out.println("Enter Prob of unsuccessfull search:");
        for (int i = 0; i <= n; i++) q[i] = sc.nextDouble();

        for (int i = 0; i <= n; i++) {
            e[i][i] = q[i];
            w[i][i] = q[i];
        }

        for (int l = 1; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l;
                e[i][j] = Double.MAX_VALUE;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                for (int r = i + 1; r <= j; r++) {
                    double t = e[i][r - 1] + e[r][j] + w[i][j];
                    if (t < e[i][j]) e[i][j] = t;
                }
            }
        }

        System.out.printf("%.4f\n", e[0][n]);
    }
}
