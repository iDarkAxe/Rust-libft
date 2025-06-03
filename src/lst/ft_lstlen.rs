use libc::c_char;

#[unsafe(no_mangle)]
pub extern "C" fn ft_lstlen(s: *const c_char) -> usize {
    if s.is_null() {
        return 0;
    }
    unsafe {
        let mut index: usize = 0;
        while *s.add(index) != 0 
        {
            index += 1;
        }
        return index;
    }
}
