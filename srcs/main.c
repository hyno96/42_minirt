# include <mlx.h>

# include "structure.h"
# include "perror.h"
# include "libft.h"
# include "mlx_window.h"
# include "objects.h"
# include "parser.h"

void    hyno_test(t_data data);

#include <stdio.h>
void    print_parsing_result(t_data *data)
{    
    printf("========== Ambient ==========\n");
    printf("color : %f %f %f\n", data->ambient.x, data->ambient.y, data->ambient.z);
    printf("\n");

    printf("========== Camera ==========\n");
    printf("origin : %f %f %f\n", data->camera.origin.x, data->camera.origin.y, data->camera.origin.z);
    printf("direction : %f %f %f\n", data->camera.direction.x, data->camera.direction.y, data->camera.direction.z);
    printf("horizontal : %f %f %f\n", data->camera.horizontal.x, data->camera.horizontal.y, data->camera.horizontal.z);
    printf("vertical : %f %f %f\n", data->camera.vertical.x, data->camera.vertical.y, data->camera.vertical.z);
    printf("focal_len : %f\n", data->camera.focal_len);
    printf("left_bottom : %f %f %f\n", data->camera.left_bottom.x, data->camera.left_bottom.y, data->camera.left_bottom.z);
    printf("\n");

    printf("========== Dot Lights ==========\n");
    t_list  *light_list;
    t_dot_light *light;
    light_list = data->dot_lights;
    size_t  i = 0;
    while (light_list)
    {
        light = (t_dot_light *)(light_list->content);
        printf("%zu'th light\n", i);
        printf("origin : %f %f %f\n", light->origin.x, light->origin.y, light->origin.z);
        printf("color : %f %f %f\n", light->color.x, light->color.y, light->color.z);
        light_list = light_list->next;
        i++;
        printf("\n");
    }
    printf("\n");

    printf("========== Object List ==========\n");
    t_list      *object_list;
    t_sphere    *sp;
    t_plane     *pl;
    t_cylinder  *cy;
    size_t      idx = 0;
    object_list = data->object_list;
    while (object_list)
    {
        if (object_list->type == SP)
        {
            sp = (t_sphere *)(object_list->content);
            printf("%zu'th object - sphere\n", idx);
            printf("origin : %f %f %f\n", sp->origin.x, sp->origin.y, sp->origin.z);
            printf("radius : %f\n", sp->radius);
            printf("color : %f %f %f\n", sp->surf.color.x, sp->surf.color.y, sp->surf.color.z);
        }
        else if (object_list->type == PL)
        {
            pl = (t_plane *)(object_list->content);
            printf("%zu'th object - plane\n", idx);
            printf("origin : %f %f %f\n", pl->origin.x, pl->origin.y, pl->origin.z);
            printf("normal : %f %f %f\n", pl->normal.x, pl->normal.y, pl->normal.z);
            printf("color : %f %f %f\n", pl->surf.color.x, pl->surf.color.y, pl->surf.color.z);
        }
        else if (object_list->type == CY)
        {
            cy = (t_cylinder *)(object_list->content);
            printf("%zu'th object - cylinder\n", idx);
            printf("origin : %f %f %f\n", cy->origin.x, cy->origin.y, cy->origin.z);
            printf("normal : %f %f %f\n", cy->normal.x, cy->normal.y, cy->normal.z);
            printf("radius : %f\n", cy->radius);
            printf("height : %f\n", cy->height);
            printf("color : %f %f %f\n", cy->surf.color.x, cy->surf.color.y, cy->surf.color.z);
        }
        else
            printf("I don't have this type\n");
        idx++;
        object_list = object_list->next;
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    t_data  data;

    if (argc != 2)
    {
        ft_perror("usage: ./minirt filename.rt");
        return (ERR_ARGS);
    }
    ft_memset((void *)&data, 0, sizeof(t_data));
    if (!parse_rt_file(argv[1], &data))
        return (ERR_PARSING);
    print_parsing_result(&data);
    if (!init_window(&data.window))
    {
        ft_perror("failed to initiative mlx window");
        return (ERR_MLX_WIN);
    }
    // // draw image
    // mlx_put_image_to_window(data.window.mlx_ptr, data.window.win_ptr, \
    //                         data.window.mlx_img.img_ptr, 0, 0);
    // hyno_test(data);
    // mlx_loop(data.window.mlx_ptr);
}