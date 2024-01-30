package cn.edu.bupt.ajax.todo.demo.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import lombok.Data;

@Data
public class Todo {
    @TableId(type= IdType.AUTO)
    private Long id;
    private String content;
}
