package cn.edu.bupt.ajax.todo.demo.controller;

import cn.edu.bupt.ajax.todo.demo.entity.Todo;
import cn.edu.bupt.ajax.todo.demo.mapper.TodoMapper;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("")
public class TodoController {
    @Resource
    TodoMapper todoMapper;

    @GetMapping(path = "")
    ModelAndView getView() {
        ModelAndView mv = new ModelAndView();
        mv.setViewName("ajax-todo");
        return mv;
    }

    @GetMapping(path = "/type/todo", produces = "application/json")
    List<Todo> list() {
        return todoMapper.selectList(null);
    }

    @PostMapping(path = "/type/todo", consumes = "application/json", produces = "application/json")
    Todo add(@RequestBody Todo todo) {
        todoMapper.insert(todo);
        return todo;
    }

    @DeleteMapping(path = "/type/todo/{id}")
    Boolean delete(@PathVariable Long id) {
        todoMapper.deleteById(id);
        return true;
    }

    @PutMapping(path = "/type/todo/{id}", consumes = "application/json", produces = "application/json")
    Todo update(@PathVariable Long id, @RequestBody Todo todo) {
       todo.setId(id);
       todoMapper.updateById(todo);
       return todo;
    }
}

