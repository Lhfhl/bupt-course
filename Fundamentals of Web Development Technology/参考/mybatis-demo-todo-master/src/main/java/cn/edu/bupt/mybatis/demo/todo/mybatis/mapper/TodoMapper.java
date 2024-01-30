package cn.edu.bupt.mybatis.demo.todo.mybatis.mapper;

import cn.edu.bupt.mybatis.demo.todo.mybatis.entity.Todo;
import org.apache.ibatis.annotations.*;

import java.util.List;

public interface TodoMapper {

    @Select("select * from todo")
    List<Todo> selectAll();

    @Select("select * from todo where id = #{id}")
    Todo selectById(int id);

    @Insert("insert into todo(content) values (#{content})")
    @Options(useGeneratedKeys = true, keyProperty = "id")
    void insert(Todo todo);

    @Delete("delete from todo where id = #{id}")
    void deleteById(int id);

    @Update("update todo set content = #{content} where id = #{id}")
    void update(Todo todo);
}
