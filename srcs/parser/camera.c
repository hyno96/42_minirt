#include "parser.h"


t_bool  parse_camera(t_line_info *line_info, char **lines, t_data *data)
{
    (void)line_info;
    (void)data;
    printf("camera\n");
    free_lines(lines);
    return (TRUE);    
}
