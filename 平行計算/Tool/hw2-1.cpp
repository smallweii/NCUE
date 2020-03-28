#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

  long filesize=0, offset=0, width=0, height=0, r_width=0, r_height=0, depth=0, color_kind_num=0, color_kind_num_important=0;
  FILE *fpbmp, *fpbmp_r;
  char pixel;
  
  fpbmp=fopen("lena.bmp","rb");

  if(!fpbmp){
    printf("Usage: ./lena BMP_FILE\n");
    return 0;
  }
  
  fseek(fpbmp, 2L, SEEK_SET);
  fread(&filesize, sizeof(char), 4, fpbmp);
  
  fseek(fpbmp, 10L, SEEK_SET);
  fread(&offset, sizeof(char), 4, fpbmp);
  
  fseek(fpbmp, 18L, SEEK_SET);
  fread(&width, sizeof(char), 4, fpbmp);
  
  fseek(fpbmp, 22L, SEEK_SET);
  fread(&height, sizeof(char), 4, fpbmp);
  
  fseek(fpbmp, 26L, SEEK_SET);
  fread(&color_kind_num, sizeof(char), 2, fpbmp);
  
  fseek(fpbmp, 28L, SEEK_SET);
  fread(&depth, sizeof(char), 2, fpbmp);
  
  fseek(fpbmp, 38L, SEEK_SET);
  fread(&r_width, sizeof(char), 4, fpbmp);
  
  fseek(fpbmp, 42L, SEEK_SET);
  fread(&r_height, sizeof(char), 4, fpbmp);
  
  fseek(fpbmp, 50L, SEEK_SET);
  fread(&color_kind_num_important, sizeof(char), 4, fpbmp);
  
  printf("\nBMP filename: ");
  
  puts(argv[1]);
  
  printf("BMP filesize: %ld byte\n",filesize);
  printf("BMP data offset: %ld\n",offset);
  printf("BMP size: %ld x %ld\n",width, height);
  printf("BMP color depth: %ld bit\n",depth);
  printf("BMP color kind number: %ld\n",color_kind_num);
  printf("BMP resolution: horizonal %.0f dpi, vertical %.0f dpi\n", r_width/39.37, r_height/39.37);
  printf("BMP important color kind number: %ld\n\n",color_kind_num_important);
  
  fpbmp_r=fopen("lena_output.bmp","wb");
  
  fseek(fpbmp, 0L, SEEK_SET);
  
  for(int i=0; i<offset; i++){
	fread(&pixel, sizeof(char), 1, fpbmp);
	fwrite(&pixel, sizeof(char), 1, fpbmp_r);
  }
  
  while(fread(&pixel, sizeof(char), 1, fpbmp) != 0){
    pixel = ~pixel;
	fwrite(&pixel, sizeof(char), 1, fpbmp_r);
  }
  
  printf("Reversing finished.\n");
  
  fclose(fpbmp);
  fclose(fpbmp_r);
  
  return 0;
}
