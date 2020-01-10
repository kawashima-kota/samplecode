#include <stdio.h>
#include <math.h>

int main(){
        FILE  *fp;
        int i,j,n;
        float p,q,f,alp,bet,h;
        float a[100],b[100],c[100],d[100],g[100];
        float v[100],u[100],m[100],k[100],rad[100];
        float gosa,sum,ave;

        p=1.0;
        q=-1;
        f=0.0;
        alp=1.0;
        bet=0.0;

        n=9;
        h=(float)1/(n+1);
        fp =fopen("kadai1-12.txt","w");

        for(j=0;j<n;j++)
                a[j]=p+p+h*h*q;
        for(j=0;j<n-1;j++){
                b[j]=-p;
                c[j+1]=b[j];
        }
        g[0]=p*alp+h*h*f;
        for(j=1;j<n-1;j++)
                g[j]=h*h*f;
        g[n-1]=p*bet+h*h*f;

        d[0]=a[0];
        for(i=1;i<n;i++){
                m[i]=c[i]/d[i-1];
                d[i]=a[i]-m[i]*b[i-1];
    }

        v[0]=g[0];
        for(i=1;i<n;i++)
                v[i]=g[i]-m[i]*v[i-1];
        u[n-1]=v[n-1]/d[n-1];
        for(i=n-2;i>=0;i--)
                u[i]=(v[i]-b[i]*u[i+1])/d[i];

        for(i=0;i<=n;i++){

                k[i]=cos(h*(i+1))-sin(h*(i+1))/tan(1);
        }
        //fprintf(fp,"分割数%d\n",n+1);
        for(i=0;i<n;i++){
                //fprintf(fp,"%2d %7.4f\n",i+1,u[i]);
                fprintf(fp,"数値解:%2d %7.4f  解析解:%2d %7.4f\n", i+1,u[i],i+1,k[i]);
                //fprintf(fp,"s=%9.6f\n" ,fabs(u[i]-k[i]));
                sum+=fabs(u[i]-k[i]);
                }
        ave=sum/n;
        fprintf(fp,"誤差平均:%9.6f\n" ,ave);
        fclose(fp);
        return 0;
}
