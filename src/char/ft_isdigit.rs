#[unsafe(no_mangle)]
pub extern "C" fn ft_isdigit(character: u32) -> u32 {
    if character >= '0' as u32 && character <= '9' as u32
    {
        return 1;
    }
    return 0;
}
