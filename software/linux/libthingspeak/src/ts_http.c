#include <ts_http.h>



ssize_t ts_http_post(ts_context_t *ctx, char *host, char *page, char *poststr)
{
	int sockfd;
	struct sockaddr_in servaddr;
	char sendline[MAXLINE + 1], recvline[MAXLINE + 1];
	ssize_t n;
	struct hostent *hptr;
	char hstr[50];
	


	if ((hptr = gethostbyname(host)) == NULL) {
		fprintf(stderr, "gethostbyname error for host: %s: %s",
			host, hstrerror(h_errno));
		return -1;
	}

	printf("hostname: %s\n", hptr->h_name);
	if ((hptr->h_addrtype == AF_INET) && (hptr->h_addr_list) != NULL) {
		printf("address: %s\n", inet_ntop(hptr->h_addrtype, hptr->h_addr_list[0], hstr, sizeof(hstr)));
	} 
	else
	{
		fprintf(stderr, "Error call inet_ntop \n");
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(80);
	inet_pton(AF_INET, hstr, &servaddr.sin_addr);
	connect(sockfd, (SA *) & servaddr, sizeof(servaddr));

    
	snprintf(sendline, MAXSUB,
		 "POST %s HTTP/1.1\r\n"
		 "Host: %s\r\n"
		 "Connection: close\r\n"
		 "X-THINGSPEAKAPIKEY: %s\r\n"
		 "Content-Type: application/x-www-form-urlencoded\r\n"
		 "Content-Length: %u\r\n\r\n"
		 "%s",
		 page, 
		 host,
		 ctx->api_key,
		 strlen(poststr),
		 poststr);
	
	printf("%s\n\n\n", sendline);

	write(sockfd, sendline, strlen(sendline));
	
	while ((n = read(sockfd, recvline, MAXLINE)) > 0)
	{
		recvline[n] = '\0';
		printf("%s", recvline);
	}
	
	close(sockfd);

	return n;
}