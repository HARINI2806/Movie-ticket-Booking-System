#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char MovieName[50];
	char Rd[50];
	int price;
	char tname[50];
	char timings[50];
	struct node *link;
};
struct ticket
{
	char Moviename[50];
	char name[50];
	char phoneNo[10];
	int tickets;
	int total;
	struct ticket *link;
};




struct node *rear=NULL,*front=NULL;
struct ticket *trear=NULL,*tfront=NULL;

void insert();
int delete();
void find();
void view_all_movies();
void book_ticket();
void view_all_transections();
int cancel_booked_ticket ();
void  find_transections();
void main()
{
	int ch;
	do{
		clrscr();
		printf("\n-----------------------------------------------------------------------------");
		printf("\n");
		printf("\t MOVIE TICKET BOOKING");
		printf("\n");
		printf("\n-----------------------------------------------------------------------------");
		printf("\npress <1> Insert Movie");
		printf("\nPress <2> Delete Movie");
		printf("\nPress <3> Find Movie");
		printf("\nPress <4> View all Movies");
		printf("\nPress <5> Book Ticket");
		printf("\nPress <6> View all booked tickets details");
		printf("\nPress <7> cancel your booked ticket");
		printf("\npress <8> Find your booked tickets details ");
		printf("\nPress <0> Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch (ch)
		{
			case 1:  clrscr();
			insert();
			getch();
			break;
			case 2: clrscr();
			delete();
			getch();
			break;
			case 3: clrscr();
			find();
			getch();
			break;
			case 4: clrscr();
			view_all_movies();
			getch();
			break;
			case 5: clrscr();
			book_ticket();
			getch();
			break;
			case 6:clrscr();
			view_all_transections();
			getch();
			break;
			case 7:clrscr();
			cancel_booked_ticket ();
			getch();
			break;
			case 8:clrscr();
			find_transections();
			getch();
			break;
			case 0:
			exit(0);
			break;
			default:printf("WRONG CHOICE !");


		}
	}while(ch!=0);
}

void insert()
{

	struct node *p;
	p= (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the following details: ");
	printf("\nEnter the Movie Name:        ");
	scanf("%s",p->MovieName);
	printf("\nEnter the Relase date:       ");
	scanf("%s",p->Rd );;
	printf("\nEnter the Ticket price:      ");
	scanf("%d",&p->price);
	printf("\nEnter the Theater Name:      ");
	scanf("%s",p->tname);
	printf("\nEnter the Timings:           ");
	scanf("%s",p->timings);
	if(!front)
	{
		front = rear = p;
		p -> link = NULL;
	}
	else
	{
		rear ->link = p ;
		rear = p;
		p ->link = NULL;
	}

	printf("\n!!!!!Insertion of movie is Success!!!!!");
}
int delete()
{
	char name[50];
	struct node *p,*q;
	if(!front)
	{
		printf("\n!!!!!No movies are inserted!!!!!\n");
		return 0;
	}
	printf("\nEnter the movie name: ");
	scanf("%s",name);
	printf("\n!!!!!Your entered movie name is: %s !!!!!",name)  ;
	p=front;
	if((strcmp((p->MovieName),name))==0)
	{
		front = front ->link;
		printf("\n!!!!!Movie:%s is deleted!!!!! ",p->MovieName );
		free(p);
		return(100);
	}
	else
	{
		while(p->link&&((strcmp((p->link->MovieName),(name)))!=0))
		{
			p=p->link;
		}
		if(!p->link)
		{
			printf("\n!!!!!No such Movie Name is Inserted!!!!! ");
			return 1;
		}
		else
		{
			q=p->link;
			p->link=q->link;
			printf("\n!!!!!Movie : %s is deleted!!!!! ",q->MovieName);
			free(q);
			return 200;
		}

	}
}
void  find()
{
	struct node *p,*q;
	char Mname[50];
	p=front;
	printf("\nEnter the movie name you want to search");
	scanf("%s",Mname);
	while(p&&(strcmp((p->MovieName),(Mname))!=0))
	{
		p=p->link;
	}
	if(!p)
	{
		printf("\n!!!!!Movie %s is not found!!!!!",Mname );
	}
	else
	{
		printf("\n!!!!!Movie :%s is found!!!!! ",Mname);
		printf("\n-----------------------------------------------------------------------------");
		printf("\nMovie details are: ");
		printf("\nMovie name:  %s ",p->MovieName);
		printf("\nMovie release date is: %s ",p->Rd);
		printf("\nMovie ticket  price is: %d ",p->price);
		printf("\n Theater name  is : %s",p->tname);
		printf("\n Movie timing is : %s",p->timings);
		printf("\n-----------------------------------------------------------------------------");
	}
}
void view_all_movies()
{
	if(front == NULL)
	{
		printf("\n!!!!!No movies are inserted!!!!!\n");
	}
	else
	{
		struct node *p = front;
		printf("\nAll movie details are: ");
		while(p != NULL)
		{
			printf("\n-----------------------------------------------------------------------------");
			printf("\nMovie details are: ");
			printf("\nMovie name:               %s",p->MovieName);
			printf("\nMovie release date is:    %s ",p->Rd);
			printf("\nMovie ticket  price is:   %d ",p->price);
			printf("\nTheater name  is :        %s",p->tname);
			printf("\nMovie timing is :         %s",p->timings);
			printf("\n-----------------------------------------------------------------------------");
			p = p -> link;
		}
	}
}
void book_ticket()
{

	int totalcost;
	struct ticket *t;
	struct node *p;
	p=front;
	t=tfront;
	t=(struct ticket*)malloc(sizeof(struct ticket));
	printf("\nEnter Movie Name : ");
	scanf("%s",t->Moviename);
	while(p&&(strcmp((p->MovieName),(t->Moviename))!=0))
	{
		p=p->link;
	}
	if(!p)
	{
		printf("\n-----------------------------------------------------------------------------");
		printf(" \nYou cannot book tickets to this movie %s as it is not inserted ", t->Moviename );
		printf("\n-----------------------------------------------------------------------------");
	}
	else
	{
		printf("\n-----------------------------------------------------------------------------");
		printf("\nYou can book tickets to this movie: %s  ", t->Moviename);
		printf("\n-----------------------------------------------------------------------------");
		printf("\nMovie details are:");
		printf("\nMovie release date is: %s",p->Rd);
		printf("\nMovie ticket  price is: %d",p->price);
		printf("\nTheater name  is : %s",p->tname);
		printf("\nMovie timing is: %s",p->timings);
		printf("\n-----------------------------------------------------------------------------");
		printf("\nEnter your name: 		     	      ");
		scanf("%s",t->name);
		printf("\nEnter your phone number: 	    	      ");
		scanf("%s",t->phoneNo);
		printf("You can only book 10 tickets");
		printf("\nEnter how many tickets do you want to book:   ");
		scanf("%d",&t->tickets);
		printf("\n-----------------------------------------------------------------------------");
		totalcost=t->tickets*p->price;
		printf("\nThe total cost is                             %d Rs",totalcost);
		printf("\n-----------------------------------------------------------------------------");
		if(!tfront)
		{
			tfront = trear = t;
			t -> link = NULL;
		}
		else
		{
			trear ->link = t;
			trear = t;
			t ->link = NULL;
		}
		printf("\n!!!!!Your Ticket is booked!!!!!\n");
	}
}
void view_all_transections()
{
	if(tfront == NULL)
	{
		printf("\n-----------------------------------------------------------------------------");
		printf("\nNo Tickets are booked");
		printf("\n-----------------------------------------------------------------------------");
	}

	else
	{
		int cost;
	       struct node *p=front;
		struct ticket *t = tfront;
		printf("\nAll   transections details are: ");
		while(t)
		{
			printf("\n-----------------------------------------------------------------------------");
			printf("\nMovie name: 		    	   %s ",t->Moviename);
			printf("\nMovie release date is:    	   %s ",p->Rd);
			printf("\nMovie ticket  price is:   	   %d ",p->price);
			printf("\nTheater name  is :       	   %s",p->tname);
			printf("\nMovie timing is :        	   %s",p->timings);
			printf("\nBooked by: 		    	   %s",t->name );
			printf("\nPhone number is: 	    	   %s",t->phoneNo);
			printf("\nNumber of tickets booked is :    %d",t->tickets);
			printf("\n-----------------------------------------------------------------------------");
			cost=(t->tickets)*(p->price);
			printf("\nTotal cost for ticktes booked is:  %d", cost);
			printf("\n-----------------------------------------------------------------------------");
			p=p->link;
			t = t -> link;
		 }
	 }
}
int cancel_booked_ticket ()
{
	char mname[50];
	char pname[50];
	struct ticket *t,*s;
	if(!front)
	{
		printf("\n!!!!!No ticket are booked to any of the movie!!!!!\n");
		return 0;
	}
	printf("Enter following details to cancel your booked ticket");
	printf("\nEnter your name : ");
	scanf("%s",pname);
	printf("\nEnter movie name : ");
	scanf("%s",mname);
	printf("\n!!!!! To comform Your  name is %s and your entered movie name is: %s and  !!!!!",pname,mname)  ;
	t=tfront;
	if(((strcmp((t->Moviename),mname))==0)&&((strcmp((t->name),mname))==0))
	{
		tfront = tfront ->link;
		printf("\n!!!!! Your ticket booked to Movie:%s is cancel!!!!! ",t->Moviename );
		free(t);
		return(100);
	}
	else
	{
		while((t->link)&&((strcmp((t->link->Moviename),(mname)))!=0)&&((strcmp((t->link->name),(pname)))!=0))
		{
			t=t->link;
		}
		if(!t->link)
		{
			printf("\n!!!!!No such Movie ticket  is booked!!!!! ");
			return 1;
		}
		else
		{
			s=t->link;
			t->link=s->link;
			printf("\n!!!!!your ticket booked to movie :%s  is  cancel!!!!! ",s->Moviename);
			free(s);
			return 200;
		}

	}
}
void  find_transections()

{
	struct node *p;
	struct ticket *t,*s;
	int cost;
	char mname[50];
	char pname[50];
	t=tfront;
	p=front;
	printf("Enter following details to view your booked ticket");
	printf("\nEnter your name : ");
	scanf("%s",pname);
	printf("\nEnter movie name : ");
	scanf("%s",mname);
	while((t)&&((strcmp((t->Moviename),(mname)))!=0)&&((strcmp((t->name),(pname)))!=0))
	{
		t=t->link;
		p=p->link;
	}
	if(!t)
	{
		printf("\n!!!!! Your Transections  details are not found please enter correct movie name  !!!!!" );
	}
	else
	{
			printf("\n!!!!!Your Transections  details are  found ");
			printf("\n-----------------------------------------------------------------------------");
			printf("\nMovie name: 		    	   %s ",t->Moviename);
			printf("\nMovie release date is:    	   %s ",p->Rd);
			printf("\nMovie ticket  price is:   	   %d ",p->price);
			printf("\nTheater name  is :       	   %s",p->tname);
			printf("\nMovie timing is :        	   %s",p->timings);
			printf("\nBooked by: 		    	   %s",t->name );
			printf("\nPhone number is: 	    	   %s",t->phoneNo);
			printf("\nNumber of tickets booked is :    %d",t->tickets);
			printf("\n-----------------------------------------------------------------------------");
			cost=(t->tickets)*(p->price);
			printf("\nTotal cost for ticktes booked is: %d", cost);
			printf("\n-----------------------------------------------------------------------------");
	}
}