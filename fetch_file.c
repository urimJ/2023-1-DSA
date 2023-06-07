#include "simple_search_engine.h"

void fetch_file() {
	total_num_of_documents = 0;
	for (int i = 1; i <= MAX_FILE_NUM; i++) {
		char file_name[100];
		sprintf(file_name, "doc%03d.txt", i);	// 파일명을 저장
		read_file(file_name, i);	//read_file 함수를 호출
		total_num_of_documents++;

	}


}




