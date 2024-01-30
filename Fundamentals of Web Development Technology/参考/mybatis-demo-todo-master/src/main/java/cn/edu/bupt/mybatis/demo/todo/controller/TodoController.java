package cn.edu.bupt.mybatis.demo.todo.controller;

import cn.edu.bupt.mybatis.demo.todo.mybatis.entity.Todo;
import cn.edu.bupt.mybatis.demo.todo.mybatis.mapper.TodoMapper;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

@Controller
@RequestMapping("/")
public class TodoController {
    @Resource
    TodoMapper todoMapper;

    @GetMapping()
    String list(Model model) {
        List<Todo> todos = todoMapper.selectAll();
        model.addAttribute("todos", todos);
        return "list_page";
    }

    @GetMapping("/add")
    String addForm() {
        return "add_page";
    }

    @PostMapping("/add")
    String add(@RequestParam String content) {
        Todo todo = new Todo();
        todo.setContent(content);
        todoMapper.insert(todo);
        return "redirect:/";
    }

    @GetMapping("/delete")
    String delete(@RequestParam int id) {
        todoMapper.deleteById(id);
        return "redirect:/";
    }

    @GetMapping("/edit")
    String editForm(Model model, @RequestParam int id) {
        Todo todo = todoMapper.selectById(id);
        model.addAttribute("todo", todo);
        return "edit_page";
    }

    @PostMapping("/edit")
    String edit(@ModelAttribute Todo todo) {
        todoMapper.update(todo);
        return "redirect:/";
    }
}

