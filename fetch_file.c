#include "simple_search_engine.h"

void fetch_file() {
	total_num_of_documents = 0;
	for (int i = 1; i <= MAX_FILE_NUM; i++) {
		char file_name[100];
		sprintf(file_name, "doc%03d.txt", i);	// ���ϸ��� ����
		read_file(file_name, i);	//read_file �Լ��� ȣ��
		total_num_of_documents++;

	}


}




