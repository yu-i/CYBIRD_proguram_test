#include<stdio.h>

//電子マネーサーバ通信
void EMcheck(int* cardre){
	int ccharge=1000;
	if(ccharge-124>=0){
		cardre[0]=1;
		cardre[1]=ccharge-124;
		cardre[2]=124;
	}
}

int main(){
	int EM,money[7]={0} ,sum=0,tmp;
	int EMre[3]={0};
	printf("電子マネーを使いますか\n使う場合は1を使わない場合は0を入力してください");
	scanf("%d",&EM);
	while(!(EM==0||EM==1)){
		printf("正しく入力してください");
		scanf("%d",&EM);
	}
	if(EM==1){
  //電子マネー部分
		EMcheck(EMre);
		if(EMre[0]==0){
			printf("エラー:引き去りできませんでした\n");
		}else{
			printf("電子マネーを使用\n残高%d円\n",EMre[1]);
		}
		return 0;
	}
  
  //入金部分
	printf("お金を一枚ずつ投入してください\n");
	while(sum<130){
		scanf("%d",&tmp);
		if(tmp==10){
			money[0]++;
			sum+=tmp;
		}else if(tmp==50){
			money[1]++;
			sum+=tmp;
		}else if(tmp==100){
			money[2]++;
			sum+=tmp;
		}else if(tmp==500){
			money[3]++;
			sum+=tmp;
		}else if(tmp==1000){
			money[4]++;
			sum+=tmp;
		}else if(tmp==5000){
			money[5]++;
			sum+=tmp;
		}else if(tmp==10000){
			money[6]++;
			sum+=tmp;
		}else{
			printf("正しいお金を投入してください");
		}
	}
  //入金種確認
	printf("\n投入した金種と枚数\n");
	if(money[6]){
		printf("10000円札%d枚\n",money[6]);
	}
	if(money[5]){
		printf("5000円札%d枚\n",money[5]);
	}
	if(money[4]){
		printf("1000円札%d枚\n",money[4]);
	}
	if(money[3]){
		printf("500円玉%d枚\n",money[3]);
	}
	if(money[2]){
		printf("100円玉%d枚\n",money[2]);
	}
	if(money[1]){
		printf("50円玉%d枚\n",money[1]);
	}
	if(money[0]){
		printf("10円玉%d枚\n",money[0]);
	}
  //購入部分
	printf("\n釣り銭の金種と枚数\n");
	sum-=130;
	if(sum>=5000){
		printf("5000円札1枚\n");
		sum-=5000;
	}
	for(tmp=0;sum>=1000;tmp++){
		sum-=1000;
	}
	if(tmp){
		printf("1000円%d枚\n",tmp);
	}
	if(sum>=500){
		printf("500円1枚\n");
		sum-=500;
	}
	for(tmp=0;sum>=100;tmp++){
		sum-=100;
	}
	if(tmp){
		printf("100円%d枚\n",tmp);
	}
	if(sum>50){
		printf("50円1枚\n");
		sum-=50;
	}
	for(tmp=0;sum>=10;tmp++){
		sum-=10;
	}
	if(tmp){
		printf("10円%d枚\n",tmp);
	}
	
  //残った手持ち金
	printf("\n手元にある金種と枚数\n");
	printf("10000円%d枚\n",1-money[6]);
	printf("5000円%d枚\n",1-money[5]);
	printf("1000円%d枚\n",1-money[4]);
	printf("500円%d枚\n",1-money[3]);
	printf("100円%d枚\n",2-money[2]);
	printf("50円%d枚\n",3-money[1]);
	printf("10円%d枚\n",15-money[0]);
}
